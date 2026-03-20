# Face Array Placeholders

This folder scaffolds future frame arrays for animated face variants.

Current status:

- the firmware still uses one active image asset
- state changes are currently handled by color and pulse behavior
- these folders are ready for later multi-frame animation work
- Alien listening now includes quizzical PNG frames
- Alien responding now includes talking PNG frames
- Alien idle now includes sleeping/dreaming PNG frames
- Alien error now includes a 6-frame placeholder set

Structure:

- `HAL/idle/`
- `HAL/listening/`
- `HAL/responding/`
- `HAL/error/`
- `ALIEN/idle/`
- `ALIEN/listening/`
- `ALIEN/responding/`
- `ALIEN/error/`

Current populated arrays:

- `ALIEN/idle/`: sleeping/dreaming 300x200 frames
- `ALIEN/listening/`: quizzical listening 300x200 frames
- `ALIEN/responding/`: talking response 300x200 frames
- `ALIEN/error/`: placeholder frames built from the static Alien face

Recommended future naming:

- `0001.png`
- `0002.png`
- `0003.png`

Potential future triggers:

- Home Assistant helper or automation selecting a face array
- wake word detected
- listening active
- response playback active
- error state
