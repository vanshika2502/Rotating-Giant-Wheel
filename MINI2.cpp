#include <graphics.h>
#include <math.h>

void drawHorse(int x, int y, int height) {
    // Draw a simple horse shape
    setcolor(YELLOW);
    rectangle(x - 10, y, x + 10, y + height); // Body
    line(x - 10, y, x - 20, y - 20); // Left leg
    line(x + 10, y, x + 20, y - 20); // Right leg
    circle(x, y - 10, 10); // Head
    line(x - 20, y - 20, x + 20, y - 20); // Mane
}

void drawCarousel(int centerX, int centerY, int radius) {
    // Draw the carousel base
    setcolor(RED);
    circle(centerX, centerY, radius); // Carousel outline
}

void drawBackground() {
    // Draw a simple background representing a park
    setcolor(GREEN);
    rectangle(0, 400, getmaxx(), getmaxy()); // Ground
    setcolor(BROWN);
    rectangle(0, 400, getmaxx(), 450); // Grass
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,NULL); // Initialize graphics mode

    int centerX = getmaxx() / 2; // Center of carousel
    int centerY = 350;            // Vertical center of carousel
    int radius = 100;             // Radius of the carousel
    float angle = 0;              // Angle for circular movement

    while (true) {
        cleardevice(); // Clear the screen

        // Draw background
        drawBackground();

        // Draw carousel
        drawCarousel(centerX, centerY, radius);

        // Calculate horse positions
        for (int i = 0; i < 4; i++) {
            int x = centerX + radius * cos(angle + (i * M_PI / 2)); // Position on carousel
            int y = centerY + radius * sin(angle + (i * M_PI / 2)); // Position on carousel
            int height = 20 + 10 * sin(angle); // Height for up and down effect
            drawHorse(x, y - height, height); // Draw horse
        }

        angle += 0.05; // Increment angle for circular movement
        delay(30); // Delay for smooth animation
    }

    closegraph(); // Close the graphics window
    return 0;
}

