#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2010

include $(TOPDIR)/rules.mk

PKG_NAME:=pvpgn
PKG_VERSION:=199.r577
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/pvpgn.berlios
PKG_HASH:=930da720eedd38c20c4304fe24dfbe9c375c3c760ce3cfa81d475fe29e3a704b

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/pvpgn
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libsqlite3 +libstdcpp +zlib
	TITLE:=A bnetd based gaming network server emulation project
	URL:=http://pvpgn.berlios.de
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pvpgn/description
 The PvPGN is a bnetd based gaming network server emulation project.
 It curently supports all Westwood Online clients (Tiberian Sun,
 Red Alert 1/2, Renegade, Emperor, NOX) and all Battle.Net clients
 (Diablo 1/2, Starcraft/Broodwar, Warcraft 2/3 ROC/TFT).
endef

CMAKE_OPTIONS += \
	-D WITH_SQLITE3=true

TARGET_CFLAGS += -Wno-long-long

PVPGN_SUPP:=pvpgn-support-1.2

define Package/pvpgn/conffiles
/opt/etc/ad.conf
/opt/etc/address_translation.conf
/opt/etc/anongame_infos.conf
/opt/etc/autoupdate.conf
/opt/etc/bnalias.conf
/opt/etc/bnban.conf
/opt/etc/bnetd.conf
/opt/etc/bnhelp.conf
/opt/etc/bnmaps.conf
/opt/etc/bnxpcalc.conf
/opt/etc/bnxplevel.conf
/opt/etc/channel.conf
/opt/etc/command_groups.conf
/opt/etc/d2cs.conf
/opt/etc/d2dbs.conf
/opt/etc/realm.conf
/opt/etc/sql_DB_layout2.conf
/opt/etc/sql_DB_layout.conf
/opt/etc/supportfile.conf
/opt/etc/topics.conf
/opt/etc/tournament.conf
/opt/etc/versioncheck.conf
endef

define Download/pvpgn_supp
	URL:=$(PKG_SOURCE_URL)
	FILE:=$(PVPGN_SUPP).tar.gz
	MD5SUM:=89d0e5bc7b87df9229d1ef8636b20a08
endef
$(eval $(call Download,pvpgn_supp))

define Build/Prepare
	$(call Build/Prepare/Default)
	tar -C $(PKG_BUILD_DIR) -xvzf $(DL_DIR)/$(PVPGN_SUPP).tar.gz
endef

define Build/InstallDev
	true
endef

define Package/pvpgn/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/bn{bot,cdb,chat,ftp,pass,stat} $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/bni{2tga,build,extract,list} $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{sha1hash,tgainfo} $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/* $(1)/opt/etc/
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/{bnetd,bntrackd,d2cs,d2dbs} $(1)/opt/sbin/
	$(INSTALL_DIR) $(1)/opt/var/{bak,bnmail,chanlogs,charinfo,charsave,clans,files,ladders,reports,status,teams,users,userscdb}
	$(INSTALL_DIR) $(1)/opt/var/bak/{charinfo,charsave}
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/var/files/* $(1)/opt/var/files/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/$(PVPGN_SUPP)/* $(1)/opt/var/files/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S97bnetd $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,pvpgn))
