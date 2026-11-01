# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2009-2018 OpenWrt.org
# Copyright (C) 2018-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=cgit
PKG_REAL_VERSION:=1.2.3
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2024-08-02
PKG_SOURCE_VERSION:=09d24d7cd0b7e85633f2f43808b12871bb209d69
PKG_SOURCE_URL:=https://git.zx2c4.com/cgit
PKG_MIRROR_HASH:=3c0249555f62b894f32eeded3254d7ac550755324387ddcdcded508f2c052cec

PKG_VERSION:=$(PKG_REAL_VERSION)_git$(subst -,,$(PKG_SOURCE_DATE))~$(call version_abbrev,$(PKG_SOURCE_VERSION))

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cgit
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Version Control Systems
  TITLE:=Web interface (cgi) for Git repositories, written in C
  URL:=https://git.zx2c4.com/cgit/
  DEPENDS:= \
	+libcharset +libopenssl +libpcre2 +luajit +zlib \
	@HAS_LUAJIT_ARCH $(ICONV_DEPENDS) $(INTL_DEPENDS)
endef

define Package/cgit/description
 Cgit is a web interface (cgi) for Git repositories, written in C
 This is an attempt to create a fast web interface for the Git
 SCM, using a built-in cache to decrease server I/O pressure.
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR)/git;  \
		make configure; \
		./configure \
			$(CONFIGURE_ARGS) \
			--with-libpcre2 \
			--with-gitconfig=/opt/etc/gitconfig \
			--with-gitattributes=/opt/etc/gitattributes \
			--with-pager=/opt/bin/less \
			--with-editor=/opt/bin/vi \
			--with-perl=/opt/bin/perl \
			--with-python=/opt/bin/python \
			--with-iconv=$(ICONV_PREFIX) \
			CFLAGS="$(TARGET_CFLAGS)" \
			CPPFLAGS="$(TARGET_CPPFLAGS)" \
			LDFLAGS="$(TARGET_LDFLAGS)" \
	)
endef

define Package/cgit/install
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_INSTALL_DIR)/opt $(1)/
endef

$(eval $(call BuildPackage,cgit))
