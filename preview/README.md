# Desktop Preview

This folder contains a lightweight local preview of the ESP32-S3-BOX-3 voice UI.

It simulates:

- idle clock mode using `src/esphome/assets/voice_pulse.png`
- listening pulse state
- responding pulse state
- error pulse state

## Run Options

### Option 1: Open directly

Open `preview/index.html` in your browser.

### Option 2: Serve it locally

From the repository root:

```bash
python3 -m http.server 8000
```

Then open:

```text
http://127.0.0.1:8000/preview/
```

To stop the server, return to the terminal where it is running and press:

```text
Ctrl+C
```

## What To Expect

- the preview window represents the BOX-3 `320x240` screen
- idle mode shows a clock with thick white hands
- active modes hide the clock and show the pulsing center visual
- the control panel lets you switch states and tweak hand thickness and pulse speed

## Asset Path

The preview uses this file directly:

```text
src/esphome/assets/voice_pulse.png
```

If you replace that asset, refresh the browser to see the updated image.
