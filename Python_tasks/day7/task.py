import cv2
import numpy as np
import matplotlib.pyplot as plt

def load_image(image_path):
    """Load an image from the specified file path."""
    image = cv2.imread(image_path)
    return image

def convert_color_spaces(image):
    """Convert the image to RGB, HSV, and Grayscale color spaces."""
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    image_hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    return image_rgb, image_hsv, image_gray

def apply_edge_detection(image_gray):
    """Apply Canny and Sobel edge detection on the grayscale image."""
    edges_canny = cv2.Canny(image_gray, 100, 200)
    sobel_x = cv2.Sobel(image_gray, cv2.CV_64F, 1, 0, ksize=5)
    sobel_y = cv2.Sobel(image_gray, cv2.CV_64F, 0, 1, ksize=5)
    sobel_combined = cv2.magnitude(sobel_x, sobel_y)
    return edges_canny, sobel_x, sobel_combined

def detect_and_analyze_contours(image_rgb, image_gray):
    """Detect and analyze contours in the grayscale image."""
    _, binary_image = cv2.threshold(image_gray, 127, 255, cv2.THRESH_BINARY)
    contours, _ = cv2.findContours(binary_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    contour_image = image_rgb.copy()
    cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2)

    for contour in contours:
        area = cv2.contourArea(contour)
        perimeter = cv2.arcLength(contour, True)
        print(f"Contour Area: {area}, Perimeter: {perimeter}")
    
    return contour_image

def display_images(images, titles):
    """Display a list of images with their respective titles."""
    fig, axs = plt.subplots(1, len(images), figsize=(20, 5))
    for i, (image, title) in enumerate(zip(images, titles)):
        axs[i].imshow(image)
        axs[i].set_title(title)
        axs[i].axis('off')
    plt.show()

def main():
    image_path = './image.jpg'
    image = load_image(image_path)
    image_rgb, image_hsv, image_gray = convert_color_spaces(image)
    edges_canny, sobel_x, sobel_combined = apply_edge_detection(image_gray)
    contour_image = detect_and_analyze_contours(image_rgb, image_gray)

    display_images(
        [image_rgb, image_hsv, image_gray],
        ["Original Image (RGB)", "Image in HSV", "Grayscale Image"]
    )
    display_images(
        [edges_canny, sobel_x, sobel_combined],
        ["Canny Edge Detection", "Sobel Edge Detection (X)", "Sobel Edge Detection (Combined)"]
    )
    display_images(
        [contour_image],
        ["Contours Detected"]
    )

if __name__ == "__main__":
    main()
