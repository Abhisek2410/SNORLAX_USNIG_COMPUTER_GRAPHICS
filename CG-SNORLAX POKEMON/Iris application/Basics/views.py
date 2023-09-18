from django.shortcuts import render
import pandas as pd
import sklearn 
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix
def Home(request):
     if(request.method=="POST"):
        data=request.POST
        sl=data.get('sl')
        sw=data.get('sw')
        pl=data.get('pl')
        pw=data.get('pw')
        path="C:\\Users\\abhis\\Desktop\\Iris\\Basics\\Iris.csv"
        data=pd.read_csv(path)
        inputs=data.drop(['Id','Species'],'columns')
        outputs=data.drop(['Id','SepalLengthCm','SepalWidthCm','PetalLengthCm','PetalWidthCm'],'columns')
        x_train,x_test,y_train,y_test=train_test_split(inputs,outputs,test_size=0.2)
        model=KNeighborsClassifier(n_neighbors=13)
        model.fit(x_train,y_train)
        result=model.predict([[sl,sw,pl,pw]])
        if len(result)!=0:
            return render(request,"Home.html",context={'result':result})
        
        
     return render(request,'Home.html')