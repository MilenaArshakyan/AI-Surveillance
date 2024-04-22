import cv2

def main():
    img = cv2.imread("images/test.webp")
    if img is None:
        print("Couldn't open the image")
        return

    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    img_lab = cv2.cvtColor(img, cv2.COLOR_BGR2Lab)
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    img_blurr = cv2.GaussianBlur(img, (7, 7), 1.5)

    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    sharpening_kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    img_sharpened = cv2.filter2D(img, -1, sharpening_kernel)

    img_median_filtered = cv2.medianBlur(img, 5)

    cv2.imshow("Original Image", img)
    cv2.imshow("RGB Image", img_rgb)
    cv2.imshow("HSV Image", img_hsv)
    cv2.imshow("Lab Image", img_lab)
    cv2.imshow("Grayscale Image", img_gray)
    cv2.imshow("Gaussian Blur", img_blurr)
    cv2.imshow("Sharpened Image", img_sharpened)
    cv2.imshow("Median Filtered", img_median_filtered)

    cv2.imwrite("image_rgb.jpg", img_rgb)
    cv2.imwrite("image_hsv.jpg", img_hsv)
    cv2.imwrite("image_lab.jpg", img_lab)
    cv2.imwrite("image_gray.jpg", img_gray)
    cv2.imwrite("image_blurred.jpg", img_blurr)
    cv2.imwrite("image_sharpened.jpg", img_sharpened)
    cv2.imwrite("image_median_filtered.jpg", img_median_filtered)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()