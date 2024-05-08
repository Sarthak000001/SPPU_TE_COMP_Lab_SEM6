import random
import re


# Dictionary of possible customer inquiries and their respective responses
responses = {
   "greeting": ["👋 Hello! Welcome to our mobile repairing shop. How can I assist you today?", "Hi there! How may I help you with your mobile? 😊", "Welcome! What seems to be the problem with your phone? 📱"],
   "farewell": ["Thank you for choosing our mobile repairing services. Have a great day! 👋", "Your satisfaction is our top priority. Goodbye! 😊", "If you have any more questions, feel free to ask. Take care and goodbye! 🌟"],
   "help": ["Sure, I'm here to help. What issues are you facing with your mobile? 🤔", "How can I assist you with your mobile repair? Please let me know. 😊", "I'm here to provide the best possible solutions for your mobile problems. What do you need help with? 🛠️"],
   "screen_cracked": ["A cracked screen / display is a common issue. We can replace the screen for you. Please bring your mobile to our shop, and our technicians will take care of it. 📲", "Oh no! A cracked screen can be quite bothersome. Don't worry, we offer screen replacement services. Visit our shop, and we'll fix it for you. 😊"],
   "battery_problem": ["If you're experiencing battery issues, we can replace your mobile's battery. Bring it to our shop, and we'll ensure it gets fixed. 🔋", "Battery problems are quite common. We can replace your mobile's battery with a new one. Please visit our shop for assistance. 😊"],
   "software_issue": ["Software issues can often be resolved by resetting your mobile or updating its software. We can assist you with that. Please bring your phone to our shop, and our technicians will help you out. 🔄", "Software problems can be frustrating. We recommend trying a software reset or update. If the issue persists, our technicians can assist you further. Just drop by our shop. 😊"],
   "water_damage": ["Water damage can be critical for mobiles. We suggest immediately turning off your device and bringing it to our shop for professional repair. Do not attempt to power it on. 💧", "Water damage requires immediate attention. Please switch off your mobile, remove any SIM cards or memory cards, and bring it to our shop. Our experts will assess the damage and offer a suitable solution. 😊"],
   "default": ["I apologize, but I couldn't understand your request. 😕", "Apologies, I didn't quite get that. Could you please rephrase? 🤔", "I'm still learning. Can you provide more information? 📚"]
}


# Function to handle customer inquiries
def respond_to_inquiry(inquiry):
   inquiry = inquiry.lower()
   if re.search(r"\b(?:hello|hi)\b", inquiry):
       return random.choice(responses["greeting"])
   elif re.search(r"\b(?:goodbye|bye)\b", inquiry):
       return random.choice(responses["farewell"])
   elif re.search(r"\b(?:help|support)\b", inquiry):
       return random.choice(responses["help"])
   elif re.search(r"\b(?:screen|cracked|display)\b", inquiry):
       return random.choice(responses["screen_cracked"])
   elif re.search(r"\b(?:battery|charge)\b", inquiry):
       return random.choice(responses["battery_problem"])
   elif re.search(r"\b(?:software|update|reset)\b", inquiry):
       return random.choice(responses["software_issue"])
   elif re.search(r"\b(?:water|damage)\b", inquiry):
       return random.choice(responses["water_damage"])
   else:
       return random.choice(responses["default"])


# Displaying a pattern related to the mobile shop
print("📱🔧 Welcome to Mobile Galaxy Repair Hub! \n🔍 Your one-stop solution for mobile repairs. 🧰🛠️")
print(">>>Type 'exit' to end the conversation.\n")


# Main loop to simulate customer interaction
while True:
   user_input = input("Customer: ")


   if user_input.lower() == "exit":
       break


   bot_response = respond_to_inquiry(user_input)
   print("Chatbot: " + bot_response)
   print("\n")


print("Thank you for choosing Mobile Galaxy Repair Hub. Goodbye! 👋")


