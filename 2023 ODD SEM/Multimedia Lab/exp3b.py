import pygame
import sys
import math

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
FPS = 60
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Create the screen
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Shape Transformation")

# Clock for controlling FPS
clock = pygame.time.Clock()

def draw_shapes(frame):
    screen.fill(WHITE)
    
    # Square to Triangle to Circle transformation
    size = 100
    x, y = WIDTH // 2, HEIGHT // 2
    
    # Square
    square_rect = pygame.Rect(x - size // 2, y - size // 2, size, size)
    pygame.draw.rect(screen, BLUE, square_rect, 2)
    
    # Triangle
    triangle_points = [(x, y - size // 2), (x - size // 2, y + size // 2), (x + size // 2, y + size // 2)]
    if frame >= FPS:
        pygame.draw.polygon(screen, GREEN, triangle_points, 2)
    
    # Circle
    circle_points = []
    if frame >= 2 * FPS:
        circle_points = [(x + size // 2 * math.cos(2 * math.pi * i / 100), y + size // 2 * math.sin(2 * math.pi * i / 100)) for i in range(100)]
        for point in circle_points:
            pygame.draw.circle(screen, RED, (int(point[0]), int(point[1])), 2)

def main():
    running = True
    frame = 0
    
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        draw_shapes(frame // 2)  # Divide frame by 2 to slow down the animation
        
        pygame.display.flip()
        clock.tick(FPS)
        frame += 1
        
        if frame // 2 >= 3 * FPS:
            running = False

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()