# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

SFA (Semiconductor Fabrication Automation) is a wafer mapping and bin conversion system for semiconductor manufacturing. It processes wafer map files from EDS (Equipment Data System), converts die bin classifications, and inserts data into Oracle database.

## Build Commands

### Windows (ConvTest - Bin Conversion Test)

```bash
# Open solution in Visual Studio
ConvTest\ConvTest.sln

# Command-line build
msbuild ConvTest\ConvTest.sln /p:Configuration=Debug /p:Platform=Win32
msbuild ConvTest\ConvTest.sln /p:Configuration=Release /p:Platform=Win32
```

### Unix/HP-UX (MEMORY - Production Daemons)

Requires Oracle Pro*C precompiler and `$ORACLE_HOME` environment variable.

```bash
cd MEMORY

# Standard build (Mapcvt_Insert.exe)
make -f Makefile

# Debug build
make -f Makefile_DEBUG

# Manual mode build
make -f Makefile_Manual

# Emergency build
make -f Makefile_emergen

# Clean
make clean
```

Build produces:
- `Mapcvt_Insert.exe` - Main conversion/insert daemon
- `Map_data_task.exe` - File monitor daemon (separate makefile target)

## Architecture

### Distributed Daemon System

```
[EDS Equipment] --> .REQ files --> [Map_data_task daemon]
                                           |
                                    Message Queue (0x90000001)
                                           |
                                   [Mapcvt_Insert daemon]
                                           |
                        +------------------+------------------+
                        |                  |                  |
                   [Oracle DB]      [.RPY success]     [.EDS error]
```

**Map_data_task.c** - Monitors `/mapap/inkless/map_file_eds/` for `.REQ` files every 2 seconds, validates format, sends to message queue.

**Mapcvt_Insert.c** - Reads from message queue, applies bin conversion rules, inserts into Oracle, generates response files.

**InsertDB.pc** - Pro*C embedded SQL layer for Oracle operations.

### Inter-Process Communication

- Message queue key: `0x90000001`
- Shared memory key: `0x90000000` (process registration)
- File-based IPC: `.REQ` (request), `.RPY` (success reply), `.EDS` (error)

### Key Data Structures

**MAP_BODY** - Main wafer map structure containing:
- `stMID` (20 bytes) - Wafer/Die ID
- `stBINLT` (160,000 bytes) - Die bin classification array
- `uROWCT/uCOLCT` - Row/Column counts
- Reference die positions (REFP1-4)

**Bin notation**: `'1','2'` = good dies, `'8'` = defects, `'9'` = edge/dummy, `'D'` = post-laser fail, `'.'` = no die

## Configuration

### wafer_bin_conv_list.cfg

Located at `/users/STS/inkless/` (Unix) or `c:\temp\` (Windows).

Format:
```
WAFERSPEC WAFERID=(PSF867-22) BINCONVLIST=(15:3)
```
Maps wafer ID `PSF867-22` to convert bin 15 to bin 3.

### Unix Directories

- `/mapap/inkless/map_file_eds/` - Input wafer maps
- `/mapap/inkless/map_file_backup/` - Backup storage
- `/users/STS/inkless/LOG/SERVER/` - Log files

### Log Files

- `CvtInsertGood.YYYYMMDD` - Successful inserts
- `FileFormatErr.YYYYMMDD` - Format errors
- `InsertErr.YYYYMMDD` - Database errors

## Code Conventions

### Naming Prefixes

- `g` - globals (e.g., `gszBinListInfo`)
- `n` - integers (e.g., `nBinNo`)
- `c` - chars (e.g., `cCurValue`)
- `st` - strings/structures
- `u` - unsigned integers

### File Extensions

- `.c` - C source
- `.pc` - Pro*C (embedded SQL, preprocessed to .c)
- `.cfg` - Configuration
