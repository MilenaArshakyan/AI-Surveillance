import cv2

def resize_image(image_path, width, height):
    image = cv2.imread(image_path)
    resized_image = cv2.resize(image, (width, height))
    return resized_image