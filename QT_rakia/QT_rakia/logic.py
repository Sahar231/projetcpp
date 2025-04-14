import ollama

def get_description(image_path):
    content_description = """
    Analyze the vaccine image given. Extract the disease associated and give a general description about it
    """

    res = ollama.chat(
        model='llava',
        messages=[
            {
                'role': 'user',
                'content': content_description,
                'images': [image_path]
            }
        ]
    )
    return res['message']['content']