# Practice iterating and modifying nested lists or dictionaries.

images_metadata = {
    "image1.png": {"width": 1920, "height": 1080, "file_size_kb": 2048},
    "image2.jpg": {"width": 1280, "height": 720, "file_size_kb": 1024},
    "image3.jpeg": {"width": 800, "height": 600, "file_size_kb": 512},
}

for file_name, metadata in images_metadata.items():
    print(f"File: {file_name}")
    for key, value in metadata.items():
        print(f"  {key}: {value}")

for metadata in images_metadata.values():
    metadata["file_size_kb"] += 100 

print(images_metadata)
