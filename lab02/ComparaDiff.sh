#!/bin/sh
########################################
cd ~/labSO/lab02/
mkdir Modelo
tar -xvzf Modelo.tar.gz -C ~/labSO/lab02/Modelo

comparacao=$(diff ~/labSO/lab02/Modelo/Producao/ ~/labSO/lab02/Producao/ | awk '{ print $2 }'
)

if [ $comparacao = "idênticos:" ]; then
echo "Iguais"
else
echo "Diferentes"
echo $comparacao
#sendemail -f syanne.tavares@icen.ufpa.br -t syanne.tavares@icen.ufpa.br -u "Atenção aos arquivos de Produção" -m "Atenção!! Os arquivos de Produção estão modificados!!! $comparacao" -s cupijo.ufpa.br:587 -xu syanne.tavares@icen.ufpa.br -xp 

echo "removendo Producao/"
rm -rf Producao
echo "Extraindo modelo"
tar -xvzf Modelo.tar.gz
echo "O diretório de Produção Oficial foi restaurado!!"
fi
#Removendo Pasta modelo
rm -rf Modelo

