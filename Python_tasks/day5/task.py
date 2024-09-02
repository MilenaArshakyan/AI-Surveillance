import cv2
import numpy as np
from PIL import Image

def load_image_to_array(image_path, use_pillow=False):
    if use_pillow:
        image = Image.open(image_path)
        image_array = np.array(image)
    else:
        image = cv2.imread(image_path)
        image_array = np.array(image)
    return image_array

def basic_image_operations(image_array):
    flipped_image_horizontally = np.flip(image_array, axis=1)
    flipped_image_vertically = np.flip(image_array, axis=0)
    rotated_image = np.rot90(image_array, k=-1)
    return flipped_image_horizontally, flipped_image_vertically, rotated_image

def calculate_mean_and_variance(image_array):
    mean = np.mean(image_array)
    variance = np.var(image_array)
    return mean, variance

def main():
    image_path = './img.png'
    image_array = load_image_to_array(image_path)

    flipped_horizontally, flipped_vertically, rotated = basic_image_operations(image_array)

    mean, variance = calculate_mean_and_variance(image_array)
    print(f"Mean: {mean}, Variance: {variance}")

    cv2.imwrite('flipped_horizontally.jpg', flipped_horizontally)
    cv2.imwrite('flipped_vertically.jpg', flipped_vertically)
    cv2.imwrite('rotated_image.jpg', rotated)

if __name__ == "__main__":
    main()
