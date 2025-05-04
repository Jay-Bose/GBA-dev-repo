
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <gba_types.h>
#include <stdlib.h>

inline void bmp16_line(int x1, int y1, int x2, int y2, u32 clr,
	void* dstBase, u32 dstPitch);


// this method uses a lot of power
// A more efficient method to be introduced later.
void vid_vsync()		// basic video refresh sync
{
	while (REG_VCOUNT >= 160);	// wait till VDraw
	while (REG_VCOUNT < 160);	// wait till VBlank
}

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	// SetMode(MODE_3) { REG_DISPCNT = MODE_3 };
	REG_DISPCNT = MODE_3;

	bmp16_line(1, 1, 5, 5, RGB5(10, 10, 10), VRAM, 2);

	while (1) {

		// vid_vsync();
		
	}
	
	
}

//! Draw a line on a 16bpp canvas
inline void bmp16_line(int x1, int y1, int x2, int y2, u32 clr,
    void* dstBase, u32 dstPitch)
{
    int ii, dx, dy, xstep, ystep, dd;
    u16* dst = (u16*)(dstBase + y1 * dstPitch + x1 * 2);
    dstPitch /= 2;

    // --- Normalization ---
    if (x1 > x2)
    {
        xstep = -1;  dx = x1 - x2;
    }
    else
    {
        xstep = +1;  dx = x2 - x1;
    }

    if (y1 > y2)
    {
        ystep = -dstPitch;   dy = y1 - y2;
    }
    else
    {
        ystep = +dstPitch;   dy = y2 - y1;
    }


    // --- Drawing ---

    if (dy == 0)         // Horizontal
    {
        for (ii = 0; ii <= dx; ii++)
            dst[ii * xstep] = clr;
    }
    else if (dx == 0)    // Vertical
    {
        for (ii = 0; ii <= dy; ii++)
            dst[ii * ystep] = clr;
    }
    else if (dx >= dy)     // Diagonal, slope <= 1
    {
        dd = 2 * dy - dx;

        for (ii = 0; ii <= dx; ii++)
        {
            *dst = clr;
            if (dd >= 0)
            {
                dd -= 2 * dx; dst += ystep;
            }

            dd += 2 * dy;
            dst += xstep;
        }
    }
    else                // Diagonal, slope > 1
    {
        dd = 2 * dx - dy;

        for (ii = 0; ii <= dy; ii++)
        {
            *dst = clr;
            if (dd >= 0)
            {
                dd -= 2 * dy; dst += xstep;
            }

            dd += 2 * dx;
            dst += ystep;
        }
    }
}
