#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=duo_unix
PKG_VERSION:=1.11.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://dl.duosecurity.com
PKG_HASH:=d1249501a1780c663c4e07e8be0a6e6fcf26198ea22b8cbada7527faac9937cf

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/duo_unix/Default
	DEPENDS:=+libopenssl
	TITLE:=two-factor authentication for Unix systems
	URL:=https://github.com/duosecurity/duo_unix
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pam_duo
	$(call Package/duo_unix/Default)
	TITLE+= (PAM library)
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS+= +libpam
endef

define Package/duo_unix
	$(call Package/duo_unix/Default)
	SECTION:=admin
	CATEGORY:=Administration
endef

define Package/libduo/description
 A library for two-factor authentication as a Duo:Security service
endef

define Package/pam_duo/description
 A library for PAM authentication as a Duo:Security service
endef

define Package/duo_unix/description
 Provides simple two-factor authentication as a Duo:Security service
endef

TARGET_LDFLAGS += -lssp

CONFIGURE_ARGS += \
	--with-pam=/opt/lib/security \

define Package/pam_duo/install
	$(INSTALL_DIR) $(1)/opt/lib/security
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/security/pam_duo.so $(1)/opt/lib/security
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/pam_duo.conf $(1)/opt/etc
endef

define Package/duo_unix/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/login_duo $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/login_duo.conf $(1)/opt/etc
endef

$(eval $(call BuildPackage,pam_duo))
$(eval $(call BuildPackage,duo_unix))
