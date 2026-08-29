#include<vector>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class DocumentElement {
public :
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
    string text;
public :
    TextElement(string text) {
        this -> text = text;
    }

    string render() override {
        return this -> text;
    }
};

class ImageElement : public DocumentElement {
    string ImagePath;
public:
    ImageElement(string ImagePath) {
        this -> ImagePath = ImagePath;
    }

    string render() override {
        return "[ Image : " + this -> ImagePath + "]";
    }
};

class NewLineElement : public DocumentElement {
public :
    string render() override {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement {
public :
    string render() override {
        return "\t";
    }
};

class Document {
    vector<DocumentElement*> elements;
public :
    void addElement(DocumentElement* element) {
        elements.push_back(element);
    }

    string render() {
        string renderedDocument;
        for (auto& it : elements) {
            renderedDocument += it -> render();
        }
        return renderedDocument;
    }
};

class Persistance {
public :
    virtual void save(string) = 0;
};

class FileStorage : public Persistance {
public :
    void save(string data) override {
        ofstream file("document.txt");
        if(file.is_open()) {
            file << data;
            file.close();
            cout << "Data Successfully saved in file document.txt \n";
        } else {
            cout << "Error : Unable to open file for writing. \n";
        }
    }
};

class DBStorage : public Persistance {
public :
    void save(string data) override {
        cout << "Successfully saved the data in DB.\n";
    }
};

class DocumentEditor {
    Document* doc;
    Persistance* storage;
    string renderedDocument;

public :
    DocumentEditor(Document* doc, Persistance* storage) {
        this -> doc = doc;
        this -> storage = storage;
    }

    void addText(string text) {
        doc -> addElement(new TextElement(text));
    }

    void addImage(string path) {
        doc -> addElement(new ImageElement(path));
    }

    void addNewLine() {
        doc -> addElement(new NewLineElement());
    }

    void addTabSpace() {
        doc -> addElement(new TabSpaceElement());
    }

    string renderDocument() {
        if (renderedDocument.empty()) {
            renderedDocument = doc -> render();
        }
        return renderedDocument;
    }

    void save() {
        string data = renderDocument();
        storage -> save(data);
    }
};


int main() {
    Document* doc = new Document();
    Persistance* storage = new FileStorage();
    DocumentEditor* editor = new DocumentEditor(doc, storage);

    editor -> addText("Hi, I am Pranav Dhar Dwivedi.");
    editor -> addNewLine();
    editor -> addTabSpace();
    editor -> addImage("image.png");
    editor -> addNewLine();
    editor -> addText("Hi this side again Pranav");

    cout << editor -> renderDocument() << endl;
    editor -> save();
}