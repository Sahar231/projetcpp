from flask import Flask, request
from flask_cors import CORS
from logic import get_description

app = Flask(__name__)
CORS(app)

# API Endpoint
@app.route('/describe', methods=['POST'])
def describe():
    try:
        image_path = request.data.decode('utf-8').strip()
        if not image_path:
            return "Image path is required", 400

        # Process image
        result = get_description(image_path)
        return result

    except Exception as e:
        return str(e), 500




# Run the Flask app
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
