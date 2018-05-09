#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=incron
PKG_VERSION:=0.5.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://inotify.aiken.cz/download/incron/
PKG_HASH:=5d4abadb5f16c26e4f728a6433ad22f7655663b5812fbd4f94e852050f38e78a

include $(INCLUDE_DIR)/package.mk

define Package/incron
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libstdcpp
	TITLE:=inotify cron, a daemon system analogous to cron
	URL:=http://inotify.aiken.cz
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/incron/description
 This program is the "inotify cron" system.  You can use it a similar way
 as the regular cron. The difference is that the inotify cron handles
 filesystem events rather than time periods.
endef

define Package/incron/conffiles
/opt/etc/incron.conf
endef

define Package/incron/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/incrontab $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/incrond $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/var/spool/incron $(1)/opt/etc/incron.d
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/incron.conf.example  $(1)/opt/etc/incron.conf
	$(INSTALL_DIR) $(1)/opt/var/run
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S12incron $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,incron))
