# SPDX-License-Identifier: WTFPL
#
# Copyright (C) 2023 Entware.net

include $(TOPDIR)/rules.mk

PKG_NAME:=asterisk-chan-quectel
PKG_VERSION:=3.5
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE=2022-09-08
PKG_SOURCE_VERSION:=b3534eaedce52819ee3f61db6d191ed35177b955
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_DATE).tar.xz
PKG_SOURCE_URL:=https://github.com/IchthysMaranatha/asterisk-chan-quectel
PKG_MIRROR_HASH:=5a556e2041ced9393ab71c4bd6d3f24c53df9c68a697ce24bde6da018e4a72ec

PKG_FIXUP:=autoreconf

PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYRIGHT.txt LICENSE.txt
PKG_MAINTAINER:=Entware team, https://entware.net

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/asterisk-chan-quectel
  SUBMENU:=Telephony
  SECTION:=net
  CATEGORY:=Network
  TITLE:=channel driver for Quectel and Simcom modules
  URL:=https://github.com/IchthysMaranatha/asterisk-chan-quectel
  DEPENDS:=asterisk +alsa-lib +libsqlite3 $(ICONV_DEPENDS)
endef

define Package/asterisk-chan-quectel/description
  Asterisk channel driver for Quectel and Simcom modules,
  works with Asterisk-13+.
endef

define Package/asterisk-chan-quectel/conffiles
/opt/etc/asterisk/quectel.conf
endef

AST_PKG:=$(TOPDIR)/package/feeds/telephony/asterisk/Makefile
AST_VER:=$(shell grep '^PKG_VERSION' $(AST_PKG) | cut -d= -f2)

MAKE_FLAGS+=LD="$(TARGET_CC)"

MODULES_DIR:=/opt/lib/asterisk/modules

CONFIGURE_ARGS += \
	--with-astversion=$(AST_VER) \
	--with-iconv=$(ICONV_PREFIX)/include

CONFIGURE_VARS += \
	DESTDIR="$(MODULES_DIR)" \
	ac_cv_header_asterisk_h=yes \
	ac_cv_type_size_t=yes \
	ac_cv_type_ssize_t=yes

define Package/asterisk-chan-quectel/install
	$(INSTALL_DIR) $(1)/opt/etc/asterisk
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/etc/quectel.conf $(1)/opt/etc/asterisk
	$(INSTALL_DIR) $(1)$(MODULES_DIR)
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/chan_quectel.so $(1)$(MODULES_DIR)
endef

$(eval $(call BuildPackage,asterisk-chan-quectel))
