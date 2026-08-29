import sys
from dbhelper import DBHelper
class FlipKart :

    def __init__(self) :
        self.db = DBHelper()
        self.menu()

    def menu(self) :
        user_input = input('''
        Enter 1 to register.
        Enter 2 to login.
        Anything else to exit.
        ''')

        if user_input == '1' :
            self.register()

        elif user_input == '2' :
            self.login()

        else : sys.exit(1000)

    def register(self) :
        name = input("Enter the name :")
        email = input('Enter the email :')
        password = input('Enter the password :')
        self.db.register(name, email, password)

    def login(self) :
        email = input('Enter your registered email :')
        password = input('Enter your password :')
        self.db.login(email, password)


flipkart = FlipKart()