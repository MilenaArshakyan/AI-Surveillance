import cv2
from image_ops import resize_image

def main():
    image_path = './img.png'
    width, height = 300, 300
    
    resized_image = resize_image(image_path, width, height)
    
    cv2.imwrite('resized_image.jpg', resized_image)
    print("Image resized and saved as resized_image.jpg")

if __name__ == "__main__":
    main()