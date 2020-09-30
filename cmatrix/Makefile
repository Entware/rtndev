include $(TOPDIR)/rules.mk

PKG_NAME:=cmatrix
PKG_RELEASE:=1
PKG_VERSION:=2.0

PKG_SOURCE:=v$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/abishekvashok/cmatrix/archive/
PKG_LICENSE:=GPL-3.0
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/cmatrix
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Console based "The Matrix" like implementation
  URL:=https://github.com/abishekvashok/cmatrix
  DEPENDS:=+libncurses
  VERSION:=$(PKG_VERSION)
  MAINTAINER:=Keeper <hd_keeper@mail.ru>
endef

CONFIGURE_ARGS += --prefix=/opt --exec-prefix=/opt --without-fonts


define Package/cmatrix/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cmatrix $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/share/man/man1
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/cmatrix.1 $(1)/opt/share/man/man1/
endef

$(eval $(call BuildPackage,cmatrix))
