/* Global variables*/
#include <stdio.h>

#define PARAVTVERSION "1.1"	/*current version */
#define MAX_FILELEN 200		/*max number characters filename */
#define MIN_BDENSITY 0.3        /*minimum boundary region density in terms of average density */
                                /*used only for AUTOBORDER, valid range ]0,1[ */

#define warning2 "WARNING! the number of boundary particles is larger than task particles.\n This lead to poor performace, it may be produced by number of tasks too large,\n or BORDERSIZE too large."
                                /*used only for warning purpose*/

#define sqr(x) ((x)*(x)) 

extern int ThisTask;		/*local task */
extern int NTask;		/*total number of tasks */
extern long long int NumPart;	/*number of particles */
extern int NumThis;		/*number particles this */
extern int NumThisb;		/*number boundary particles this */
extern int fileformat;		/*input file format */

extern char InputFile[MAX_FILELEN];
extern float lbox;		/*box size */
extern float lboxx, lboxy, lboxz;	/*for rectangular shapes */
extern float dx, dy, dz;	/*cell spacing */
extern int ithis, jthis, kthis;	/*cell postion this task */
extern float bsize;		/*border size */

extern int localindex;		/*part in this task in this buffer loop */
extern int globalindex;		/*total particles allocated in this task */
extern long long int globalcount;/*read particles all tasks */
extern int currsize;		/*read particles in current loop */
extern int loopcount;		/*current loop number */
extern int root;		/* root process (default 0) */
extern int spx, spy, spz;	/*domain divisions */
extern int nneig;		/*number neigbors of non boundary particles this task */

extern FILE *filein;		/*Input File */
extern FILE *fileden;		/*output density File */
extern FILE *filevol;		/*output volume File */
extern FILE *fileneig;		/*output neigbors File */
extern FILE *fileneig2;		/*output neigbors indices File */
extern FILE *filegrid;		/*output grid File */
extern FILE *filegrid2;		/*output grid file 2 */
extern FILE *filegrad;          /*output gradient file*/


extern float *buffer;		/*Read buffer */
extern int *member;		/*save cell location for each particle */
extern float *locbuffer;	/*buffer allocated each task */
extern long long int *locind;	/*index part. for local buffer each task */

extern int stopit;

extern float minrho;

extern float pdensity;          /*particle density*/

/*! Header for the standard file format.
 *  */
extern struct io_header
{
  int npart[6];			/*!< number of particles of each type in this file */
  double mass[6];		/*!< mass of particles of each type. If 0, then the masses are explicitly
				   stored in the mass-block of the snapshot file, otherwise they are omitted */
  double time;			/*!< time of snapshot file */
  double redshift;		/*!< redshift of snapshot file */
  int flag_sfr;			/*!< flags whether the simulation was including star formation */
  int flag_feedback;		/*!< flags whether feedback was included (obsolete) */
  unsigned int npartTotal[6];	/*!< total number of particles of each type in this snapshot. This can be
				   different from npart if one is dealing with a multi-file snapshot. */
  int flag_cooling;		/*!< flags whether cooling was included  */
  int num_files;		/*!< number of files in multi-file snapshot */
  double BoxSize;		/*!< box-size of simulation in case periodic boundaries were used */
  double Omega0;		/*!< matter density in units of critical density */
  double OmegaLambda;		/*!< cosmological constant parameter */
  double HubbleParam;		/*!< Hubble parameter in units of 100 km/sec/Mpc */
  int flag_stellarage;		/*!< flags whether the file contains formation times of star particles */
  int flag_metals;		/*!< flags whether the file contains metallicity values for gas and star particles */
  unsigned int npartTotalHighWord[6];	/*!< High word of the total number of particles of each type */
  int flag_entropy_instead_u;	/*!< flags that IC-file contains entropy instead of u */
  char fill[60];		/*!< fills to 256 Bytes */
}
header;				/*!< holds header for snapshot files */
