import os
from gtts import gTTS
def read_text_file(file_path):
    """Reads content from a text file."""
    if not os.path.exists(file_path):
        raise FileNotFoundError(f"The file {file_path} does not exist.")
    
    with open(file_path, 'r', encoding='utf-8') as file:
        return file.read()

def text_to_speech(text, language='en', output_file='output.mp3'):
    """
    Converts the given text to speech using Google Text-to-Speech (gTTS).

    """
    tts = gTTS(text=text, lang=language, slow=False)
    tts.save(output_file)


def select_language():
    """Displays the list of available languages and allows the user to select one."""
    supported_languages = {
        '1': ('English', 'en'),
        '2': ('Spanish', 'es'),
        '3': ('French', 'fr'),
        '4': ('German', 'de'),
        '5': ('Italian', 'it'),
        '6': ('Portuguese', 'pt'),
        '7': ('Dutch', 'nl'),
        '8': ('Russian', 'ru'),
        '9': ('Chinese', 'zh'),
        '10': ('Hindi', 'hi')
    }

    print("Please select a language for the Text-to-Speech conversion:")
    for key, (language_name, _) in supported_languages.items():
        print(f"{key}. {language_name}")
    
    choice = input("Enter the number of your language choice: ").strip()
    
    if choice in supported_languages:
        selected_language = supported_languages[choice]
        print(f"You have selected: {selected_language[0]}")
        return selected_language[1]
    else:
        print("Invalid selection. Defaulting to English.")
        return 'en'

def main(file_path):
    """Main function to read project updates from a file and convert to speech."""
    try:
        project_updates = read_text_file(file_path)
        language = select_language()
        print(f"Reading project updates in language: {language}")
        text_to_speech(project_updates, language)
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    file_path = 'C:\IIT Bombay\Python\project_updates-english.txt'
    """Change the file path above as per system and requirements"""
    main(file_path)
