AI face talking animation export pack

Contents:
- talk_frame_*.png                 Transparent source frames
- ai_face_talking.gif              Preview animation
- ai_face_talk_*.c                 LVGL true-color-alpha image arrays
- ai_face_talk_*_rgb565.h          Raw RGB565 sprite arrays
- ai_face_talk_*_mask_1bit.h       1-bit alpha masks for raw sprite drawing
- ai_face_talking_anim.h           Convenience LVGL declarations array

Recommended:
- Use the LVGL .c files if you want transparency preserved.
- Use the RGB565 + 1-bit mask headers if you want lighter raw rendering on ESP32.

Suggested talking loop timing:
- 70 to 110 ms per frame

Example LVGL frame cycling:
    static uint8_t idx = 0;
    lv_img_set_src(img, ai_face_talking_frames[idx]);
    idx = (idx + 1) % AI_FACE_TALKING_FRAME_COUNT;

If colors look wrong on your panel, your display config may need 16-bit byte swapping.
