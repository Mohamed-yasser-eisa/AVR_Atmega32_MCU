#ifndef __STD_MACROS_HEADER__
#define __STD_MACROS_HEADER__


/*******************************************************************************
*@file: std_macros.h
*@author: Mohamed Yasser
*@brief: standard macros
*******************************************************************************/





/*------------------- macros functions: -------------------------*/
#define REG_SIZE (8)
#define SET_BIT(REG,BIT)  (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)  (REG &= (~(1<<BIT)))
#define TOG_BIT(REG,BIT)  (REG ^= (1<<BIT))
#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define ROR(REG,NUM)      (REG = ((REG<<(REG_SIZE-NUM))|(REG>>NUM)))
#define ROL(REG,NUM)      (REG = ((REG>>(REG_SIZE-NUM))|(REG<<NUM)))
/*============================ end ==============================*/




#endif //__STD_MACROS_HEADER__