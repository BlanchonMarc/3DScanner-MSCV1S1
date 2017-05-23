#include "reconstruction_thread.h"
// Constructor
reconstruction_thread::reconstruction_thread(dataclass *thedatabase)
{
    Database = thedatabase;

    //Calling Reconstruction class
    recproject  =  new Reconstruction(Database) ;
}

void reconstruction_thread::run()
{

    if(Database->getRecSettingsStatus()==2)
        Database->m_Mesh = recproject->reconstruction(false,Database);
    else
        Database->m_Mesh = recproject->reconstruction(true,Database);

    Database->setReconstructionState(1);

}
