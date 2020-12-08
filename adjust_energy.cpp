#include "adjust_energy.h"
#include "ui_adjust_energy.h"

adjust_energy::adjust_energy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adjust_energy)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QVector <QString> list;
    list<<"交流校准"<<"直流校准"<<"相位校准"<<"谐波相位校准";
    ui->check_type->set_items(list);
    list.clear();
    list<<"档位0"<<"档位1"<<"档位2"<<"档位3"<<"档位4"<<"档位5"<<"档位6"<<"档位7"<<"档位8"\
          <<"档位9"<<"档位10"<<"档位11"<<"档位12"<<"档位13"<<"频率"<<"自动换挡";
    ui->gear->set_items(list);
}

adjust_energy::~adjust_energy()
{
    delete ui;
}

void adjust_energy::on_enable_std_num_clicked()
{

}

void adjust_energy::on_check_adjust_clicked()
{

}

void adjust_energy::on_start_adjust_clicked()
{

}

void adjust_energy::on_read_old_num_clicked()
{

}

void adjust_energy::on_count_num_clicked()
{

}

void adjust_energy::on_stop_adjust_clicked()
{

}

void adjust_energy::on_init_num_clicked()
{

}

void adjust_energy::on_init_std_value_clicked()
{

}

void adjust_energy::on_write_num_clicked()
{

}

void adjust_energy::on_normal_clicked()
{

}

void adjust_energy::on_out_std_clicked()
{

}

void adjust_energy::on_stop_out_clicked()
{

}
