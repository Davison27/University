#include "./include/game.h"

void Game::setLetterIntroduced(string letter)
{
    if (!hasIntroducedLetter(letter))
        this->lettersIntroduced.push_back(letter);
}

bool Game::hasIntroducedLetter(string letter)
{
    for (int i = 0; i < this->lettersIntroduced.size(); i++)
        if (this->lettersIntroduced[i] == letter)
            return true;
    return false;
}

string Game::getRandomSentenceFromFile()
{
    srand(time(NULL));
    string filename("./database/secret_sentences.txt"); //File name
    char *line = nullptr;                               //Here we store the sentences while we iterate
    size_t len = 0;                                     //It is used to started always at the beginning of a line
    vector<string> sentences;                           //List of sentences

    FILE *input_file = fopen(filename.c_str(), "r"); //Opens the file
    if (input_file == nullptr)
        exit(-1);

    while ((getline(&line, &len, input_file)) != -1) //We store the sentences in the list
        sentences.push_back(line);

    fclose(input_file);

    int randomSentencePosition = rand() % 5; //Generate a random number
    string randomSentence = sentences[randomSentencePosition];
    randomSentence.pop_back(); //Removes the \n
    return randomSentence;     //Returns a random sentence from the list
}

string Game::EncriptSentence(string sentence)
{
    string sentenceWith_ = "";                  //Here we store the _ sentence
    for (int c = 0; c < sentence.length(); c++) //We create the _ sentence
    {
        if (sentence[c] == ' ')
            sentenceWith_.append(" ");
        else if (sentence[c] == ',')
            sentenceWith_.append(",");
        else if (sentence[c] == '.')
            sentenceWith_.append(".");
        else if (sentence[c] == ':')
            sentenceWith_.append(":");
        else if (sentence[c] == ';')
            sentenceWith_.append(";");
        else if (sentence[c] == '-')
            sentenceWith_.append("-");
        else
            sentenceWith_.append("_");
    }

    return sentenceWith_; //Returns the _ sentence
}

bool isConsonant(string c) //Returns true if c is a consonant
{
    c[0] = toupper(c[0]);
    if (!isdigit(c[0]))
        if (c != "A" && "E" && "I" && "O" && "U")
            return true;

    return false;
}

bool isVowel(string c) //Returns true if c is a vowel
{
    c[0] = toupper(c[0]);
    if (!isdigit(c[0]))
        if (c[0] == 'A' || c[0] == 'E' || c[0] == 'I' || c[0] == 'O' || c[0] == 'U')
            return true;

    return false;
}

bool Game::letterIsInSentence(string letter) //Returns true if letter is in sentence
{
    char actualLetter = letter[0]; //actualLetter contains the letter. If we dont do that, we cannot compare a string position (char) with a string
    for (int i = 0; i < this->sentence.size(); i++)
        if (this->sentence[i] == actualLetter)
            return true;
    return false;
}

void Game::sustituteSentence(string letter) //Change the _ with the letter
{
    for (int i = 0; i < this->sentence.size(); i++)
        if (this->sentence[i] == letter[0])
            this->secretSentence[i] = letter[0];
}

int puntuation(int playerPoints, string letter, string secretSentence)
{
    if (isVowel(letter))
        playerPoints = playerPoints - 50;
    else if (isConsonant(letter))
    {
        int cont = 0;
        for (int i = 0; i < sizeof(secretSentence); i++)
            if (secretSentence[i] == letter[0])
                cont++;

        playerPoints = playerPoints + (cont * 50);
    }

    return playerPoints;
}

int Game::howManyTimesLetterInSentence(string letter)
{
    int count = 0;
    for (int i = 0; i < this->sentence.size(); i++)
        if (this->sentence[i] == toupper(letter[0]))
            count++;

    return count;
}

int Game::pair(int sd)
{
    if (this->getSdPlayerOne() == sd)
        return getSdPlayerTwo();
    else if (this->getSdPlayerTwo() == sd)
        return getSdPlayerOne();
    else
        return -1;
}