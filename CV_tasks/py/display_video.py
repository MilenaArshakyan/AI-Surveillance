import cv2

def main():
    webcam = cv2.VideoCapture(0)
    if not webcam.isOpened():
        print("Error: couldn't open webcam.")
        exit()

    while True:
        valid_frame, frame = webcam.read()
        if not valid_frame:
            break

        cv2.imshow("WebCam", frame)
        if cv2.waitKey(1) == ord(' '):
            break

    webcam.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()