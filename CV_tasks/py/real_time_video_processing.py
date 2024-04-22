import cv2
import numpy as np
import time

def main():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Failed to open webcam")
        return

    flip_vertical = False
    flip_horizontal = False
    grayscale = False
    hsv = False
    lab = False
    blur = False
    median_filter = False
    draw_shape = False

    while True:
        ret, frame = cap.read()
        if not ret:
            print("Failed to capture frame")
            break

        if flip_vertical:
            frame = cv2.flip(frame, 0)
        if flip_horizontal:
            frame = cv2.flip(frame, 1)
        if grayscale:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        if hsv:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        if lab:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2Lab)
        if blur:
            frame = cv2.GaussianBlur(frame, (7, 7), 1.5)
        if median_filter:
            frame = cv2.medianBlur(frame, 5)
        if draw_shape:
            cv2.rectangle(frame, (50, 50), (200, 200), (0, 255, 0), 3)

        current_time = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        cv2.putText(frame, current_time, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

        active_effects = []
        if flip_vertical:
            active_effects.append("Flip Vertical")
        if flip_horizontal:
            active_effects.append("Flip Horizontal")
        if grayscale:
            active_effects.append("Grayscale")
        if hsv:
            active_effects.append("HSV")
        if lab:
            active_effects.append("LAB")
        if blur:
            active_effects.append("Gaussian Blur")
        if median_filter:
            active_effects.append("Median Filter")
        if draw_shape:
            active_effects.append("Shape")

        if active_effects:
            effect_text = ', '.join(active_effects)
            cv2.putText(frame, "Effects: " + effect_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

        cv2.imshow("Webcam", frame)

        key = cv2.waitKey(30) & 0xFF
        if key == ord('q'):
            break
        elif key == ord('v'):
            flip_vertical = not flip_vertical
        elif key == ord('h'):
            flip_horizontal = not flip_horizontal
        elif key == ord('g'):
            grayscale = not grayscale
        elif key == ord('s'):
            hsv = not hsv
        elif key == ord('l'):
            lab = not lab
        elif key == ord('b'):
            blur = not blur
        elif key == ord('m'):
            median_filter = not median_filter
        elif key == ord('r'):
            draw_shape = not draw_shape

    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
