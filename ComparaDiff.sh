#!/bin/sh
########################################
zip Modelo -r Producao/ && zip Modelo -r Producao/
comparacao=$(diff ~/lab02/Modelo/ ~/lab02/Producao/)

if [  -z $comparacao ]; then
echo "Iguais"
else
echo "Diferentes"
echo $comparacao
#sendemail -f syanne.tavares@icen.ufpa.br -t syanne.tavares@icen.ufpa.br -u "Atenção aos arquivos de Produção" -m "Atenção!! Os arquivos de Produção estão modificados!!! $comparacao" -s cupijo.ufpa.br:587 -xu syanne.tavares@icen.ufpa.br -xp Rosiane2610

echo "removendo Producao/"
rm -rf Producao
echo "Extraindo modelo"
unzip Modelo.zip
echo "O diretório de Produção Oficial foi restaurado!!"
fi
rm -rf Modelo.zip
