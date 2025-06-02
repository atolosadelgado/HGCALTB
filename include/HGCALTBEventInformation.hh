#ifndef HGCALTBEventInformation_h
#define HGCALTBEventInformation_h

#include "G4VUserEventInformation.hh"
#include "G4Types.hh"
#include "G4LogicalVolume.hh"

#include <vector>


class HGCALTBEventInformation : public G4VUserEventInformation {
public:
    HGCALTBEventInformation() = default;
    ~HGCALTBEventInformation() override = default;
    struct SecondaryInfo {
        G4int pdgID = {0};
        G4double energy = {0};
        G4LogicalVolume* birthVolume = {nullptr};
        G4int trackID = {-1};
        G4bool exited = {false};
    };

    void RegisterSecondary(const SecondaryInfo& info) {
        secondaries.push_back(info);
    }

    void MarkSecondaryAsExited(G4int trackID) {
        for (auto& s : secondaries) {
            if (s.trackID == trackID) {
                s.exited = true;
                return;
            }
        }
    }

    const std::vector<SecondaryInfo>& GetSecondaries() const {
        return secondaries;
    }

    virtual void Print() const override {
        G4cout << "HGCALTBEventInformation print" << G4endl;
    }
private:
    std::vector<SecondaryInfo> secondaries;

};


#endif
