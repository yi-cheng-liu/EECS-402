


BALANCE_REQUIRED = 100
def accure_one_month_interest(balance_amount, do_print):
    if balance_amount < BALANCE_REQUIRED:
        print("ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0,"
               + "but the value " + str(balance_amount) + "was provided!")
        return False
    if do_print == True:
            print("Accruing interest for 1 month:")
    
    
    print("Hello World")


accure_one_month_interest(10, True)