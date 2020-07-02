#include <stdio.h>
#include<math.h>
double r2(double[],double[]);
int N,D=2,O=3;

void main()
{ printf("\n");
    printf(" --------------------- Linear Regression Model ------------------------\n");
    printf(" \n");
    printf(" Enter 1 for the Theory behind the Machine Learning model.\n Enter 2 for Model training and Predictions.\n");
    
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\tIn statistics, linear regression is a linear approach to modelling the relationship between a scalar response\n(or dependent variable) and one or more explanatory variables (or independent variables). The case of one \nexplanatory variable is called simple linear regression. For more than one explanatory variable, the process\nis called multiple linear regression.This term is distinct from multivariate linear regression, where\nmultiple correlated dependent variables are predicted, rather than a single scalar variable\
In linear regression,\nthe relationships are modeled using linear predictor functions whose unknown model parameters are estimated\nfrom the data. Such models are called linear models\n\n");
    printf("R2 / Pearsons correlation coefficient squared\n\n");
    printf("R-squared is a goodness-of-fit measure for linear regression models. This statistic indicates the percentage of the\nvariance in the dependent variable that the independent variables explain collectively. R-squared measures the strength\nof the relationship between your model and the dependent variable on a convenient 0-100 percent scale.\
Linear regression\nidentifies the equation that produces the smallest difference between all of the observed values and their fitted values.\nTo be precise, linear regression finds the smallest sum of squared residuals that is possible for the dataset.\n");

    
    case 2:    
    {
  
    






printf("\nEnter the number of features\n");
    double lr;
     
     scanf("%d",&N);
     printf("Enter the value of the Learning Rate: \n");
     scanf("%lf",&lr);
double X[O][N],Z[O][N];
int i,j;
int a,b,g;
    long c;
 double prod[] = {0,0,0};
      
      double W[]= {10,20,30};
      double Y[N];
double yhat[N];
double R[N];

for(i=0;i<N;i++)
{ printf("Input values of Training samples %d\n",i+1);
    for(j=0;j<D;j++)
    scanf("%lf",&X[j][i]);
    printf("\n");
}
for(i=0;i<O;i++)
{
    X[2][i]=X[0][i]*X[1][i];
    
}

for(i=0;i<N;i++)
{for (j = 0;j<O;j++)
Z[i][j] = X[i][j];

} 

printf("Enter predicted values\n");


    for(j=0;j<N;j++)
    scanf("%lf",&Y[j]);
    
    

   
    
  for(c=1;c<10000000;c++)
   {

        
    
      for(b=0;b<N;b++)
              {
                  yhat[b]=(W[0]*Z[0][b])+(W[1]*Z[1][b])+(W[2]*Z[2][b]);
              
               
          
              }
               /*for(j=0;j<N;j++)
                printf("%f\t",yhat[j]);*/
    
      for(i=0;i<N;i++)
      {
          R[i]=yhat[i]-Y[i]; //delta
          
          
      }
      /* for(j=0;j<N;j++)
                printf("%f\t",R[j]);
                printf("\n");
               // printf("%d\t%d\n%d\t%d",X[0][0],X[1][0],X[0][1],X[0][2]);*/
      
      
      
      for(a=0;a<N;a++)
      {
      prod[0] += (R[a]*X[0][a]);
       prod[1] += (R[a]*X[1][a]);
       prod[2] += (R[a]*X[2][a]);
      }
      /*printf("%f \t",prod[0]);
      printf("%f\t",prod[1]);
      printf("%f",prod[2]);*/
      
    prod[0] *= lr;
    prod[1] *= lr;
    prod[2] *= lr;
    //printf("%f ",prod[0]);
      //printf("%f\n",prod[1]);
    
    
   for(g=0;g<O;g++)
   {
       
       W[g] = W[g] - prod[g];
   }
    
}
printf("\n");

printf("weights are : %lf\t%lf\t%lf\n",W[0],W[1],W[2]);
printf("\n");
printf("The equation of your line is Y = %lfX1 + %lfX2 + %lfX1*X2\n",W[0],W[1],W[2]);
printf("\n");

    double r=r2(Y,yhat);
    
printf("The value of R2 is: %lf\n",r);
printf("If the value of R2 is 1 : This means that you have a perfect model\n");
printf("\n");
printf("If the value of R2 is > 0.5 , This means that you have a model that is performing statistically better than random guessing.\n");
printf("\n");
printf("If the value of R2 is less than 0.5 : Try using better features or use a different model.");
printf("\n");

    
}
break;
default: printf("invalid");
}


}
double r2(double y1[],double y2[])
{
    int p,q;
    double mean;
    for(p=0;p<N;p++)
    {
        mean+=y1[p];
    }
    mean/=N;
    double r[N];
    double s[N];
    double sum=0,sum1=0;
    for(q=0;q<N;q++)
    {
       r[q]=y1[q]-mean;
           s[q]=y1[q]-y2[q];
    }
    for(p=0;p<N;p++)
    {
        sum+=pow(r[p],2);
        sum1+=pow(s[p],2);
    }
    double R2=1-(sum1/sum);
    return (R2);
}

