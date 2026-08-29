import mysql.connector
import sys

class DBHelper :
    def __init__(self) :
        try : 
            self.conn = mysql.connector.connect(host = 'localhost', user = 'root', password = '', database = 'hit-db-demo')

            self.myCursor = self.conn.cursor()
        except :
            print('Some error occured.')
            sys.exit(0)
        else :
            print('Connected to Database.')

    def register(self, name, email, password) :
        query = "INSERT INTO users (id, name, email, password) VALUES (NULL, %s, %s, %s)"
        values = (name, email, password) ## sql need values in this format fstring will not work here
        try :
            self.myCursor.execute(query, values)
            self.conn.commit()
        except :
            print('Try again user not registered.')
        else :
            print('Successfully Inserted.')
        
        self.menu()

    def login(self, email, password) :
        query = 'SELECT * FROM users WHERE email LIKE %s AND password LIKE %s'
        values = (email, password)
        try :
            self.myCursor.execute(query, values)
            response = self.myCursor.fetchall()
            if not response :
                print('Login Failed. Email not found.')
            elif password != response :
                print('Wrong Password.')
            else :
                print('Login Successful.')
            print(response)
        except :
            print('Login Failed. Please try again.')