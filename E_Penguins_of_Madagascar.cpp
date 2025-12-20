#include <iostream>

using namespace std;

class Researcher {
public:
  int id;
  string name;

  Researcher(int researcher_id, string &researcher_name)
      : id(researcher_id), name(researcher_name) {
    cout << "  Researcher ructor called (ID: " << id << ", Name: " << name
         << ")\n";
  }

  void displayResearcherInfo() {
    cout << "Scholar: " << name << " (ID: " << id << ")";
  }
};

class AI_Division : virtual public Researcher {
public:
  string division_name;

  AI_Division(int researcher_id, string &researcher_name, string &ai_div_name)
      : Researcher(researcher_id, researcher_name), division_name(ai_div_name) {
    cout << "  AI_Division ructor called (Division: " << division_name << ")\n";
  }

  void displayAIDivisionInfo() {
    displayResearcherInfo();
    cout << ", Division: " << division_name;
  }
};

class Bio_Division : virtual public Researcher {
public:
  string division_name;

  Bio_Division(int researcher_id, string &researcher_name, string &bio_div_name)
      : Researcher(researcher_id, researcher_name),
        division_name(bio_div_name) {
    cout << "  Bio_Division ructor called (Division: " << division_name
         << ")\n";
  }

  void displayBioDivisionInfo() {
    displayResearcherInfo();
    cout << ", Division: " << division_name;
  }
};

class AI_Project : public AI_Division {
public:
  string project_title;
  double project_funding;

  AI_Project(int researcher_id, string &researcher_name, string &ai_div_name,
             string &title, double funding)
      : AI_Division(researcher_id, researcher_name, ai_div_name),
        project_title(title), project_funding(funding) {
    cout << "  AI_Project ructor called (Title: " << project_title
         << ", Funding: $" << project_funding << ")\n";
  }

  void displayAIProjectInfo() {
    displayAIDivisionInfo();
    cout << ", AI Project: " << project_title << " (Funding: $"
         << project_funding << ")";
  }
};

class Bio_Project : public Bio_Division {
public:
  string project_title;
  double project_funding;

  Bio_Project(int researcher_id, string &researcher_name, string &bio_div_name,
              string &title, double funding)
      : Bio_Division(researcher_id, researcher_name, bio_div_name),
        project_title(title), project_funding(funding) {
    cout << "  Bio_Project ructor called (Title: " << project_title
         << ", Funding: $" << project_funding << ")\n";
  }

  void displayBioProjectInfo() {
    displayBioDivisionInfo();
    cout << ", Bio Project: " << project_title << " (Funding: $"
         << project_funding << ")";
  }
};

class Final_Report : public AI_Project, public Bio_Project {
public:
  Final_Report(int researcher_id, string &researcher_name, string &ai_div_name,
               string &ai_title, double ai_funding, string &bio_div_name,
               string &bio_title, double bio_funding)
      : Researcher(researcher_id, researcher_name),
        AI_Project(researcher_id, researcher_name, ai_div_name, ai_title,
                   ai_funding),
        Bio_Project(researcher_id, researcher_name, bio_div_name, bio_title,
                    bio_funding) {
    cout << "  Final_Report ructor called.\n";
  }

  void displayFinalReport() {
    
    cout << "Name:" << name << " (ID: " << id << ")\n";

    cout << "\nAI Research Details:\n";
    AI_Project::displayAIProjectInfo();
    cout << endl;

    cout << "\nBio Research Details:\n";
    Bio_Project::displayBioProjectInfo();
    cout << endl;
  }
};

int main() {
  cout << "--- Creating Final_Report object ---\n";

  Final_Report prantor_report(2307006, "Prantor", "Machine Learning Division",
                              "Phi-123 Model Optimization", 45000.0,
                              "Plant Genetics Division",
                              "Cactus Drought Resistance Study", 20000.0);
  prantor_report.displayFinalReport();

  return 0;
}