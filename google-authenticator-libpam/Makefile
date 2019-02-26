#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=google-authenticator-libpam
PKG_VERSION:=1.05
PKG_REV:=7365ed10d54393fb4c100cac063ae8edb744eac6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/google/google-authenticator-libpam
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/google-authenticator-libpam
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libpam +libqrencode
	TITLE:=Google Authenticator PAM module
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/google-authenticator-libpam/description
 Google Authenticator PAM module.
endef

define Package/google-authenticator-libpam/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/google-authenticator \
	    $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/security
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/security/pam_google_authenticator.so \
	    $(1)/opt/lib/security
endef

$(eval $(call BuildPackage,google-authenticator-libpam))
