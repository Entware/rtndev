#
# Copyright (C) 2011-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Official dist source is painfully slow from Russia

include $(TOPDIR)/rules.mk

PKG_NAME:=urbackup-server
PKG_VERSION:=2.5.31
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:= \
	http://hndl.urbackup.org/Server/$(PKG_VERSION) \
	https://www.urbackup.org/downloads/Server/$(PKG_VERSION)
PKG_HASH:=2a5aaa020b900d48e7083c04e9a1e95e0bfb065dfe8dc43b51eac82440107001

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/urbackup-server
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libcurl +zlib +libstdcpp +zstd
	TITLE:=UrBackup Server
	URL:=http://www.urbackup.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/urbackup-server/description
 UrBackup is an easy to setup Open Source client/server backup system.
endef

CONFIGURE_ARGS += \
	--enable-embedded-cryptopp \
	--oldincludedir="$(STAGING_DIR)/opt/include"

TARGET_LDFLAGS += -lssp

define Package/urbackup-server/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/var/urbackup
	$(INSTALL_DIR) $(1)/opt/share/urbackup
	$(CP) $(PKG_INSTALL_DIR)/opt/share/urbackup/* $(1)/opt/share/urbackup
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S60urbackup-server $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,urbackup-server))
