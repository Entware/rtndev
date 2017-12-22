#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=urbackup-server
PKG_VERSION:=2.1.20
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://hndl.urbackup.org/Server/$(PKG_VERSION)
PKG_HASH:=de90c73703e168bec73e3fd167065818dbcf0f9adc5f5d5ca7ec3193557e5a1a

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/urbackup-server
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libcurl +zlib +libstdcpp
	TITLE:=UrBackup Server
	URL:=http://www.urbackup.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/urbackup-server/description
 UrBackup is an easy to setup Open Source client/server backup system
endef

CONFIGURE_ARGS += \
	--enable-embedded-cryptopp \
	--oldincludedir="$(STAGING_DIR)/opt/include" \

define Package/urbackup-server/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/var/urbackup
	$(INSTALL_DIR) $(1)/opt/share/urbackup
	$(CP) $(PKG_INSTALL_DIR)/opt/share/urbackup/* $(1)/opt/share/urbackup/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S60urbackup-server $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,urbackup-server))
