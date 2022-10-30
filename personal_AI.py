import pyttsx3
import speech_recognition as sr
import datetime
import webbrowser
import pyaudio
import wikipedia
import subprocess
import requests
import json
import time

engine = pyttsx3.init(
    "sapi5"
)  # Microsoft developed speech API,Helps in synthesis and recognition of voice of AI
voices = engine.getProperty("voices")
rate = engine.getProperty('rate')
engine.setProperty('rate', rate + 2)
  
volume = engine.getProperty('volume')
engine.setProperty('volume', volume-0.1)
# print(voices[1].id)
engine.setProperty(
    "voice", voices[1].id
)  # Voice id helps us to select different voices,voice[0].id = Male voice,voice[1].id = Female voice


def speak(audio):
    engine.say(audio)
    engine.runAndWait()  # Without this command, speech will not be audible to us


def wishme():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("good morning Sarthak")
        print(
            "good morning Sarthak",
            "\n",
            datetime.datetime.now().day,
            "-",
            datetime.datetime.now().month,
            "-",
            datetime.datetime.now().year,
            "\n",
        )
    elif hour >= 12 and hour < 18:
        speak("good afternoon Sarthak")
        print(
            "good afternoon Sarthak",
            "\n",
            datetime.datetime.now().day,
            "-",
            datetime.datetime.now().month,
            "-",
            datetime.datetime.now().year,
            "\n",
        )
    else:
        speak("good evening Sarthak")
        print(
            "good evening Sarthak",
            "\n",
            datetime.datetime.now().day,
            "-",
            datetime.datetime.now().month,
            "-",
            datetime.datetime.now().year,
            "\n",
        )
    speak("hello, I am Aura")
    print("Hello, I am Aura....", "\n")
    speak("How may I help you!")
    print("How may I help you!....", "\n")


def takecommand():
    # important thing for our A.I. assistant is that it should take command with the help of the microphone of the user's system. So, now we will make a takeCommand() function.
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("listening....")
        r.pause_threshold = 2
        r.energy_threshold = 5000
        audio = r.listen(source)

    try:
        print("reconizing...")
        query = r.recognize_google(
            audio, language="en-in"
        )  # Using google for voice recognition
        print("User said :", query, "\n")
    except Exception as e:
        # print(e)
        speak("please say it again")
        print("please say it again")
        return "None"
    return query

if __name__ == "__main__":

    wishme()
    while True:
        query = takecommand().lower()
        if "youtube" in query:
            webbrowser.open("www.youtube.com")
            
        elif "google" in query:
            from google import search

            query = query.replace("google", " ")
            for j in search(query, tld="co.in", num=10, stop=10, pause=2):
                print(j)
                
        elif "stackoverflow" in query:
            webbrowser.open("stackoverflow.com")
            
        elif "github" in query:
            webbrowser.open("https://github.com/")
            
        elif "facebook" in query:
            webbrowser.open("https://www.facebook.com/")
        elif "quora" in query:
            webbrowser.open("quora.com")
        elif "download movies" in query:
            webbrowser.open("https://www.afilmywap.onl/")
        elif "cricket score" in query:
            webbrowser.open("cricbuzz.com")
        elif "twitter" in query:
            webbrowser.open("twitter.com")
        elif "wikipedia" in query:
            speak("searching wikipedia...")
            query = query.replace("wikipedia", " ")
            results = wikipedia.page(query).content
            print(results)
            speak(results)
        elif "news" in query:
            url = ("https://newsapi.org/v2/top-headlines?" "country = in&" "apiKey= 6d3ba62c2cb34bdbbea78b25af7cce19")
            #url+='fbb87832cfbc4d78aefcd40b4416fbb3'

            try:
                response = requests.get(url)
            except:
                engine.say("can, t access link, plz check you internet ")

            news = json.loads(response.text)
            print(
                    "##############################################################","\n"
                )
            print(str(news),end='')
            engine.say(str(news))
            print("______________________________________________________\n")

            engine.runAndWait()

            print(str(news),end='')
            engine.say(str(news))
            engine.runAndWait()
            print("..............................................................")
            time.sleep(3)

        elif "calculator" in query:
            webbrowser.open("calculator.com")
        elif "amazon" in query:
            webbrowser.open("https://www.amazon.in/")
        elif "translator" in query:
            webbrowser.open("googletranslator.com")
        elif "weather" in query:
            webbrowser.open("accuweather.com")
            
            
        ## for these applications use the location of them in your device;
        elif "whatsapp" in query:
            subprocess.Popen("")
        elif "teams" in query:
            subprocess.Popen(
                ''
            )
        elif "zoom" in query:
            subprocess.Popen("")
        elif "grammarly" in query:
            subprocess.Popen(
                ""
            )
        elif "media player" in query:
            subprocess.Popen("")
        elif "inbox" in query:
            webbrowser.open("")
        elif "spotify" in query:
            subprocess.Popen("")
        elif "notepad" in query:
            subprocess.Popen("")
        elif "vscode" in query:
            subprocess.Popen(
                ""
            )
        elif "python" in query:
            subprocess.Popen(
                ''
            )

        elif "exit" in query:
            speak("thank you ")
            print("thank you..")
            exit()
        else:
            continue

#vscode://vscode.github-authentication/did-authenticate?windowid=1&code=8fe786983bb99e9b182a&state=9621b0d4-6946-473a-a12d-5bf6f7d5327e