from flask import Flask, request, jsonify, send_file

app = Flask(__name__)

PASSWORDS = {
    'backup123': 'basic',
    'equipment456': 'advanced'
}

@app.route('/data.json')
def get_json_data():
    password = request.args.get('password')
    access = PASSWORDS.get(password, None)

    if not access:
        return jsonify({'status': 'Invalid password'}), 403

    data = {
        'status': 'OK',
        'access_level': access,
        'destination': {
            'lat': 52.123456,
            'lon': 21.123456
        },
        'hazards': []
    }

    if access == 'advanced':
        data['hazards'] = [
            {'lat': 52.123900, 'lon': 21.124000},
            {'lat': 52.124200, 'lon': 21.123100}
        ]

    return jsonify(data)

@app.route('/data.png')
def get_image():
    password = request.args.get('password')
    if password not in PASSWORDS:
        return 'Invalid password', 403
    return send_file('map_dummy.png', mimetype='image/png')

if __name__ == '__main__':
    app.run(host='::', port=5000, debug=False)  # <-- Perubahan disini