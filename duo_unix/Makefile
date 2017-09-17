#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=duo_unix
PKG_VERSION:=1.10.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://dl.duosecurity.com
PKG_HASH:=e2df2be50539c54c87cdc4964fdfee0fbd79a3f15fdfd807e94941291b5d6197

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/duo_unix/Default
	DEPENDS:=+libopenssl
	TITLE:=two-factor authentication for Unix systems
	URL:=https://github.com/duosecurity/duo_unix
	MAINTAINER:=Entware team, http://entware.net
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
