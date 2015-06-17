/*
 *  Delphes: a framework for fast simulation of a generic collider experiment
 *  Copyright (C) 2012-2014  Universite catholique de Louvain (UCL), Belgium
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef JetFlavorAssociation_h
#define JetFlavorAssociation_h

/** \class JetFlavorAssociation
 *
 *  Find origin of jet and evaluate jet flavor
 *
 *  \author P. Demin - UCL, Louvain-la-Neuve
 *
 */

#include "classes/DelphesModule.h"
#include "classes/DelphesClasses.h"
#include <map>

class TObjArray;
class DelphesFormula;

class ExRootFilter;
class PartonClassifier;
class PartonClassifierLHEF;

class JetFlavorAssociation: public DelphesModule
{
public:

  JetFlavorAssociation();
  ~JetFlavorAssociation();

  void Init();
  void Process();
  void Finish();

  void GetAlgoFlavor(Candidate *jet, TIter &itPartonArray, TIter &itPartonArrayLHEF);
  void GetPhysicsFlavor(Candidate *jet, TIter &itPartonArray, TIter &itPartonArrayLHEF);

private:

  Double_t  fDeltaR;

  PartonClassifier  *fClassifier; //!
  PartonClassifierLHEF *fClassifierLHEF; //!

  ExRootFilter *fFilter;
  ExRootFilter *fFilterLHEF;

  TIterator *fItPartonInputArray; //!
  TIterator *fItPartonInputArrayLHEF; //!
  TIterator *fItJetInputArray; //!
  TIterator *fItParticleInputArray; //!

  const TObjArray *fPartonInputArray; //!
  const TObjArray *fPartonInputArrayLHEF; //!
  const TObjArray *fJetInputArray; //!
  const TObjArray *fParticleInputArray; //!

  ClassDef(JetFlavorAssociation, 1)
};

#endif