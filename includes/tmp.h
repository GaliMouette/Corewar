//  Live and cycles
#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40
#define MEM_SIZE                (6 * 1024)
#define IDX_MOD                 512         //  Index modulo
//  Reserved characters
#define DIRECT_STR              "%"

//  Sizes (in bytes)
#define IND_SIZE        2           //  Short int (-32768 to 32767)
#define DIR_SIZE        4           //  Int       (-2147483648 to 2147483647)
#define REG_SIZE        DIR_SIZE

//  Registres
#define REG_NUMBER              16  //  Number of registres (Starts at 1 to 16)
