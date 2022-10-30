import pandas as pd
import numpy as np
import matplotlib
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split 
from sklearn.metrics import accuracy_score
#from sklearn.externals import joblib
from sklearn import tree



music_data=pd.read_csv('music.csv')
'''print("The whole data looks like")
print(music_data)'''


X=music_data.drop(columns=['genre'])
'''print("The input looks like")
print(X)'''


y=music_data['genre']
'''print("The output looks like")
print(y)'''


X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.15)
model=DecisionTreeClassifier()
model.fit(X_train,y_train)


#joblib.dump('music-recommender.joblib')
#model=joblib.load('music-recommender.joblib')


predictions=model.predict(X_test)
'''print(predictions)
print(y_test)
'''


accuracy=accuracy_score(y_test,predictions)
'''print("The accuracy of the model is-")
print(accuracy)
'''


tree.export_graphviz(model,out_file='music-recommender.dot',feature_names=['age','gender'],class_names=sorted(y.unique()),label=True,rounded=True,filled=True)

