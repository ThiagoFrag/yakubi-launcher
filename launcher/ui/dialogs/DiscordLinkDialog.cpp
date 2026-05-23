// SPDX-License-Identifier: GPL-3.0-only
#include "DiscordLinkDialog.h"
#include "ui_DiscordLinkDialog.h"

#include <QDesktopServices>
#include <QPushButton>
#include <QSettings>
#include <QUrl>

static constexpr const char* DISCORD_INVITE_URL = "https://mc.lin.lgbt/discord";
static constexpr const char* SETTINGS_KEY = "yakubi/discordLinkDismissed";

DiscordLinkDialog::DiscordLinkDialog(QWidget* parent) : QDialog(parent), ui(new Ui::DiscordLinkDialog)
{
    ui->setupUi(this);

    auto* linkBtn = ui->buttonBox->button(QDialogButtonBox::Ok);
    linkBtn->setText(tr("Vincular Discord"));

    auto* laterBtn = ui->buttonBox->button(QDialogButtonBox::Cancel);
    laterBtn->setText(tr("Agora não"));

    connect(linkBtn, &QPushButton::clicked, this, &DiscordLinkDialog::onLinkClicked);
    connect(laterBtn, &QPushButton::clicked, this, &DiscordLinkDialog::onDismiss);
}

DiscordLinkDialog::~DiscordLinkDialog()
{
    delete ui;
}

void DiscordLinkDialog::onLinkClicked()
{
    QSettings settings;
    settings.setValue(SETTINGS_KEY, true);
    QDesktopServices::openUrl(QUrl(DISCORD_INVITE_URL));
    accept();
}

void DiscordLinkDialog::onDismiss()
{
    reject();
}

void DiscordLinkDialog::showIfNeeded(QWidget* parent)
{
    QSettings settings;
    if (settings.value(SETTINGS_KEY, false).toBool())
        return;

    DiscordLinkDialog dlg(parent);
    dlg.exec();
}
