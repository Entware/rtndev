#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ctags
PKG_VERSION:=p5.9.20210314.0
PKG_REV:=0e4c307b305d99ab9f56f7b346da52ad69457768
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_REV).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/universal-ctags/ctags
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/ctags
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=$(ICONV_DEPENDS) +jansson +libyaml +libxml2
	TITLE:=Universal Ctags
	URL:=https://ctags.io
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ctags/description
 Universal Ctags generates an index (or tag) file of language objects found in
 source files for many popular programming languages. This index makes it easy
 for text editors and other tools to locate the indexed items. Universal Ctags
 improves on traditional ctags because of its multilanguage support, its ability
 for the user to define new languages searched by regular expressions, and its
 ability to generate emacs-style TAGS files.
endef

CONFIGURE_ARGS += \
	--disable-seccomp \
	--enable-debugging \
	--enable-dependency-tracking \
	--enable-etags \
	--enable-macro-patterns \
	--enable-readlib \
	--enable-tmpdir=/opt/tmp

CONFIGURE_VARS += \
	PYTHON=$(STAGING_DIR_HOSTPKG)/bin/python3

define Build/Configure
	$(call Build/Configure/Default)
	( cd $(PKG_BUILD_DIR); \
	$(HOSTCC) -o packcc misc/packcc/packcc.c \
	)
endef

define Package/ctags/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{c,read}tags $(1)/opt/bin
	$(LN) ctags $(1)/opt/bin/etags
endef

$(eval $(call BuildPackage,ctags))
