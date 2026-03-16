# AGENTS.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Project Overview

This is a mixed-language learning/practice repository combining:
- A Node.js/Express backend with an OpenAI integration (`index.js` at root)
- A frontend skeleton (`src/`) — currently empty HTML/CSS/JS files
- Standalone C programming exercises (`public/*.c`) each compiled to a `.exe`
- An HTML learning exercise (`properties.xml`)

## Commands

### Node.js (backend)

Install dependencies:
```
npm install
```

Start the server (no npm script defined — run directly):
```
node index.js
```

The server requires `OPENAI_API_KEY` to be set in `.env`. The `.env` file currently contains a placeholder value and must be filled before running.

### C programs (public/)

The project uses GCC via MinGW (installed at `C:\msys64\mingw64\bin\gcc.exe`). Compile a single file:
```
gcc -g public\<filename>.c -o public\<filename>.exe
```

Run a compiled executable:
```
.\public\<filename>.exe
```

Each `.c` file is a self-contained program with its own `main()`.

### Tests

No test framework is configured. The `test` script in `package.json` is a placeholder that exits with an error.

## Architecture

### Backend — `index.js`

Exports an Express `Router` (`aiRouter`) with a single route:
- `GET /summary/:id` — calls the OpenAI Chat Completions API to summarize a job offer. The system prompt and user prompt are in Spanish. It reads `OPENAI_API_KEY` from `.env` via `process.loadEnvFile()`.

**Known bugs in `index.js` as of last edit:**
- `package.json` declares `"type": "commonjs"` but `index.js` uses ES module `import` syntax — these are incompatible. Either change to `"type": "module"` or rewrite with `require()`.
- Typo: `aopenai.chat.completions.create(...)` should be `openai.chat.completions.create(...)`.
- Wrong response property: `completion.choices?.[0]?.content` should be `completion.choices?.[0]?.message?.content`.
- Invalid model name: `'gpt-6.22.0'` is not a real OpenAI model name.

### Frontend — `src/`

Contains `index.html`, `css/style.css`, and `js/script.js`, all currently empty. Intended as the web UI counterpart to the backend.

### C exercises — `public/`

Six standalone C programs demonstrating different concepts: bitwise flags (`main.c`), function pointer arrays (`app.c`), structs and pointers (`db.c`, `script.c`), conditional logic (`component.c`), and a Hello World baseline (`index.c`). Each has a compiled `.exe` alongside it.

## Environment

`.env` must define:
```
OPENAI_API_KEY=<your key here>
```
