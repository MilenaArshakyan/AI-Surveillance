import cv2

def main():
    # Load an image from disk
    image = cv2.imread("images/test.webp")
    if image is None:
        print("Error: Couldn't load the image.")
        return

    text = "text"
    text_position = (50, 50)
    font_face = cv2.FONT_HERSHEY_SIMPLEX
    font_scale = 1.0
    text_color = (0, 255, 0)
    thickness = 2

    cv2.putText(image, text, text_position, font_face, font_scale, text_color, thickness)

    line_start = (100, 100)
    line_end = (300, 100)
    line_color = (0, 0, 255) 

    cv2.line(image, line_start, line_end, line_color, thickness)

    rect_top_left = (100, 150)
    rect_bottom_right = (300, 300)
    rect_color = (255, 0, 0)

    cv2.rectangle(image, rect_top_left, rect_bottom_right, rect_color, thickness)

    circle_center = (200, 400)
    radius = 50
    circle_color = (255, 255, 0) 

    cv2.circle(image, circle_center, radius, circle_color, thickness)

    cv2.imshow("Annotated Image", image)

    cv2.imwrite("annotated_image.jpg", image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()