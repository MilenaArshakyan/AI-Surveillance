import cv2

# Load an image
image = cv2.imread('images/test.webp')

if image is None:
    print("Error: Couldn't load the image.")
    exit(-1)

# Resizing
resized_image = cv2.resize(image, (400, 300))
cv2.imshow("Resized Image", resized_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("resized_image.jpg", resized_image)

# Flipping vertical
flipped_vertical = cv2.flip(image, 0)
cv2.imshow("Flipped Vertical Image", flipped_vertical)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("flipped_vertical_image.jpg", flipped_vertical)

# Flipping horizontal
flipped_horizontal = cv2.flip(image, 1)
cv2.imshow("Flipped Horizontal Image", flipped_horizontal)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("flipped_horizontal_image.jpg", flipped_horizontal)

# Cropping
x, y, width, height = 100, 100, 40, 40
cropped_image = image[y:y+height, x:x+width]
cv2.imshow("Original Image", image)
cv2.waitKey(0)
cv2.imshow("Cropped Image", cropped_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("cropped_image.jpg", cropped_image)

# Rotating
angle = 45
center = (image.shape[1] // 2, image.shape[0] // 2)
rotation_matrix = cv2.getRotationMatrix2D(center, angle, 1.0)
rotated_image = cv2.warpAffine(image, rotation_matrix, (image.shape[1], image.shape[0]))
cv2.imshow("Rotated Image", rotated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("rotated_image.jpg", rotated_image)
