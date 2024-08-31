import os
from pathlib import Path

def read_image_list(file_path):
    try:
        with open(file_path, 'r') as file:
            image_list = file.read().splitlines() 
        return image_list
    except FileNotFoundError:
        print(f"Error: The file {file_path} was not found.")
        return []

def process_images(image_list, directory):
    for image_name in image_list:
        image_path = Path(directory) / image_name
        try:
            if image_path.exists():
                print(f"Processing image: {image_name}")
            else:
                raise FileNotFoundError(f"Image file '{image_name}' not found.")
        except FileNotFoundError as e:
            print(e)
        finally:
            print(f"Finished attempting to process: {image_name}\n")

def list_image_files(directory):
    try:
        image_files = [f for f in os.listdir(directory) if f.endswith(('.png', '.jpg', '.jpeg'))]
        return image_files
    except FileNotFoundError:
        print(f"Error: The directory {directory} was not found.")
        return []

def main():
    image_list_file = "images.txt"
    image_directory = "./images"
    image_list = read_image_list(image_list_file)

    process_images(image_list, image_directory)

    all_image_files = list_image_files(image_directory)
    print("List of all image files in the directory:")
    for image_file in all_image_files:
        print(image_file)

if __name__ == "__main__":
    main()
