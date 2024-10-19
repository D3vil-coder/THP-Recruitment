# Import necessary libraries
from transformers import pipeline, GPT2LMHeadModel, GPT2Tokenizer
import json

# Step 1: Load Data (This should be project-specific data about the IIT Bombay humanoid project)
def load_project_data(file_path):
    with open(file_path, 'r') as f:
        data = json.load(f)
    return data

# Step 2: Preprocessing (Simple tokenization and cleanup for now, can be expanded)
def preprocess_data(data):
    # This function would involve steps like tokenization, cleaning unnecessary details, etc.
    processed_data = {}
    for key, value in data.items():
        processed_data[key.lower()] = value  # Simple conversion to lowercase for uniformity
    return processed_data

# Step 3: Define the Chatbot's Response Function
def generate_response(question, model, tokenizer, project_data):
    # max_length=80 
    # max_new_tokens=100
    # Tokenize input question
    inputs = tokenizer(question, return_tensors="pt")

    # Check for specific keywords in the question (like 'objectives', 'team members')
    if 'objectives' in question.lower():
        return project_data.get('objectives', 'No information available on objectives.')
    elif 'objective' in question.lower():
        return project_data.get('objectives', 'No information available on objectives.')
    elif 'progress' in question.lower():
        return project_data.get('progress', 'No information available on project progress.')
    elif 'team' in question.lower():
        team_info = project_data.get('team_members',[])
        response = "The team members involved in the project are:\n"
        for member in team_info:
            response += f"\t* {member['name']} ({member['role']}) - {member['department']}\n"    
        return response
    
    
    
    # If the question doesn't match any of the above, generate a generic response
    outputs = model.generate(**inputs, max_new_tokens=200)
    response = tokenizer.decode(outputs[0], skip_special_tokens=True)
    return response

# Step 4: Setup the Model and Tokenizer
def setup_model():
    # Load pretrained GPT-2 model and tokenizer from Hugging Face
    model_name = "gpt2"  # Can be swapped with GPT-3 if necessary
    model = GPT2LMHeadModel.from_pretrained(model_name)
    tokenizer = GPT2Tokenizer.from_pretrained(model_name)
    tokenizer.pad_token_id=tokenizer.eos_token_id + 1
    return model, tokenizer

# Step 5: Example of integrating LangChain for more advanced query understanding
# For now, keeping it simple with the basic structure
# LangChain would later allow us to chain models, retrievers, etc.
def chatbot():
    # Load and preprocess project data
    project_data = load_project_data('data_thp.json')
    processed_data = preprocess_data(project_data)
    
    # Setup model and tokenizer
    model, tokenizer = setup_model()

    print("Welcome to the IIT Bombay Humanoid Project Chatbot!")
    print("You can ask questions about the project's objectives, progress, or team members.")
    print("Type 'exit' to quit the chatbot.")

    while True:
       # Take user input
       user_question = input("\nYour question: ")
       
       # Exit condition
       if user_question.lower() == 'exit':
           print("Thank you for using the chatbot! Goodbye!")
           break
       # Generate response
       response = generate_response(user_question, model, tokenizer, processed_data)
       
       # Print the response
       print("Chatbot Response:", response)

if __name__ == "__main__":
   chatbot()
